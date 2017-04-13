extern IGUIWindow *window[64]; /* A vector of windows that we reuse. */
extern IGUIEditBox *px, /* Position X. */
				   *py, /* Position Y. */
				   *pz, /* Position Z. */
				   *pq,
				   *pcx,
				   *pcy,
				   *pcz,
				   *v0,
				   *ang; /* angle X. */

extern stringw AboutText; /* Show a texte loaded from a XML on the "About" window. */
extern IGUIStaticText *InformationText; /* The right bottom debug text. */

/* Create a splash apresentation box. */
void SplashBox();

/* Create a messagebox with software's information. */
void AboutBox();

/* Create a tools box for force fields manipulation. */
void ToolsBoxE();
void ToolsBoxC();