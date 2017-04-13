extern bool BF1,
		    BF2,
		    BQ,
		    BT,
		    BC,
		    BB,
		    BP,
		    QL,
		    LH,
		    LO;
extern float stime;
extern float UX,
			 UY,
			 UZ,
			 sy0,
		     sz0,
			 Vi,
			 Viy,
			 Viz,
			 angle,
			 lim;

/* Loads system assets such as fonts and cutscenes. Must have "system.h" included on your code.
returns 0 if couldn't load a file and returns 1 if all went well. */
int LoadSystem();

/* Change the GUI skin apparence. (transparency, color 1, color 2) */
void SetSkinApparence(s32 alpha, SColor Color_1, SColor Color_2);

/* Load the system's configuration xml file. */
int LoadXML();