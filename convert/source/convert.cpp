/*
 * Copyright 2009 Mukunda Johnson (mukunda.com)
 * 
 * This file is part of SNESMOD - gh.mukunda.com/snesmod
 *
 * See LICENSING.txt
 */
 
#include <string>
#include <stdio.h>
#include "inputdata.h"
#include "itloader.h"
#include "it2spc.h"

const char USAGE[] = {
	"SNESMOD (C) 2009 Mukunda Johnson (mukunda.com)\n\n"
	"\n"
	"Usage: smconv [options] [input]\n"
	"\n"
	"Options\n"
	"-s                  Soundbank creation mode.\n"
	"--soundbank           (Can specify multiple files with soundbank mode.)\n"
	"                      (Otherwise specify only one file for SPC creation.)\n"
	"                      (Default is SPC creation mode)\n"
	"-o [file]           Specify output file or file base.\n"
	"--output              (Specify SPC file for -b option)\n"
	"                      (Specify filename base for soundbank creation)\n"
	"                      (Required for soundbank mode)\n"
	"-u [vol]            Specify overall volume for SPC creation.\n"
	"--volume              (Valid values are 0-127)\n"
	"                      (Default value is 80)\n"
	"-a [artist-name]    Specify artist name for SPC creation.\n"
	"--artist\n"
	"-t [song-title]     Specify song title for SPC creation.\n"
	"--song-title\n"
	"-g [name]           Specify game title for SPC creation.\n"
	"--game-title\n"
	"-l [seconds:fade]   Specify length pair for SPC creation.\n"
	"--length              (Default values are 180:5000)\n"
	"                      (\"seconds\" must be exactly 3 characters long.)\n"
	"                      (\"fade\" must be exactly 5 characters long.)\n"
	"                      (Example: one minute long with 5 seconds of fade-out is \"060:50000\".)\n"
	"-h                  Use HIROM mapping mode for soundbank.\n"
	"--hirom\n"
	"-v                  Enable verbose output.\n"
	"--verbose\n"
	"--help              Show Help\n"
	"\n"
	"Typical options to create soundbank for project:\n"
	"  smconv -s -o build/soundbank -h input1.it input2.it\n"
	"\n"
	"And for IT->SPC:\n"
	"  smconv input.it\n"
	"\n"
	"TIP: use -v to view how much RAM the modules will use.\n"
};

std::string PATH;
bool VERBOSE;

int main( int argc, char *argv[] ) {
	
	ConversionInput::OperationData od( argc, argv );

	VERBOSE = od.verbose_mode;

	if( argc < 2 ) {
		od.show_help = true;
	}

	if( od.show_help ) {
		printf( USAGE );
		return 0;
	}

	if( od.output.empty() ) {
		printf( "missing output file\n" );
		return 0;
	}

	if( VERBOSE )
		printf( "Loading modules...\n" );

	ITLoader::Bank bank( od.files );

	if( VERBOSE )
		printf( "Starting conversion...\n" );

	IT2SPC::Bank result( bank, od.hirom );
	
	// export products
	if( od.spc_mode ) {
		result.MakeSPC( od );
	} else {
		result.Export( od.output.c_str() );
	}
	
	return 0;
}
