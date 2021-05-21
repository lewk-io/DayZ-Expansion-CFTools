class CfgPatches
{
	class DayZExpansion_CFTools
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
            "DayZExpansion_Scripts",
			"GameLabs_Scripts"
		};
	};
};

class CfgMods
{
	class DayZExpansion_CFTools
	{
		dir="DayZ-Expansion-CFTools";
		name="DayZ Expansion CFTools";
		author="@Lewk_io";
		version="0.1";
		extra=0;
		type="mod";
		dependencies[]={"Game", "World"};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]={"DayZ-Expansion-CFTools/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"DayZ-Expansion-CFTools/scripts/4_World"};
			};
		};
	};
};