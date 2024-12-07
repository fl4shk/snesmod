/*
 * Copyright 2009 Mukunda Johnson (mukunda.com)
 * 
 * This file is part of SNESMOD - gh.mukunda.com/snesmod
 *
 * See LICENSING.txt
 */
 
#ifndef __INPUTDATA_H
#define __INPUTDATA_H

// param parser

#include <stdlib.h>
#include <string>
#include <vector>
#include "basetypes.h"

namespace ConversionInput {
/*
	class EffectData {
	public:
		EffectData( const TiXmlElement * );
		std::string filename;
		std::string id;
		
		int force_filter;
		
	};
*/
	/*
	class SampleData {

	public:
		int index;
		int force_filter;
		int force_loop_filter;
		std::string id;
	
		SampleData( const TiXmlElement * );
		SampleData( const EffectData & );
	};
*/
	/*
	class ModuleData {

	private:
		u8 ConvertBitString( const char * );
		u8 TranslatePercentage( int );
		
	public:

		ModuleData( const TiXmlElement *source );
		~ModuleData();
		std::string filename;
		std::string id;
		
		u8	EDL;
		u8	EFB;
		u8	EVL;
		u8	EVR;
		u8	EON;
		u8	COEF[8];
		
		std::vector<SampleData*> samples;
	};
*/
	/*
	typedef struct {

		std::vector<const char *> files;
		bool hirom;
		std::string output;
	} SoundbankInfo;

	class SoundbankData {

	public:
		
		SoundbankData( const SoundbankInfo &info );
		
		std::string output;
		bool hirom;
		
		std::vector<ModuleData*> modules;
		std::vector<EffectData*> effects;
	};
*/
	class OperationData {

	public:

		class ExtraSpcOptions {

		public:
			std::string volume;
			std::string artist;
			std::string song_title;
			std::string game_title;
			std::string length_seconds;
			std::string length_fade;
		};

	private:
		

	public:

		~OperationData();

		OperationData( int argc, char *argv[] );

		ExtraSpcOptions extra_spc_options;

		std::string output;
		bool hirom;
		std::vector<const char *> files;
		bool spc_mode;
		bool verbose_mode;
		bool show_help;

	};
}

#endif
