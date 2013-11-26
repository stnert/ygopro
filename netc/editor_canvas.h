#ifndef _EDITOR_CANVAS_H_
#define _EDITOR_CANVAS_H_

#include "wx/wx.h"
#include "wx/glcanvas.h"
#include "deck_data.h"
#include <vector>

namespace ygopro
{
    
    struct TextureInfo;
    
	class wxEditorCanvas : public wxGLCanvas {

	private:
		wxGLContext* glcontext;
		unsigned int glwidth;
		unsigned int glheight;
        TextureInfo* t_buildbg;
        DeckData current_deck;
        
	public:
		wxEditorCanvas(wxFrame* parent, int id, int* args);
		virtual ~wxEditorCanvas();

        bool loadDeck(const wxString& file);
		void drawScene();

		// events
		void eventResized(wxSizeEvent& evt);
		void eventRender(wxPaintEvent& evt);
		void eventMouseMoved(wxMouseEvent& evt);
		void eventMouseWheelMoved(wxMouseEvent& evt);
		void eventMouseDown(wxMouseEvent& evt);
		void eventMouseReleased(wxMouseEvent& evt);
		void eventMouseLeftWindow(wxMouseEvent& evt);

		DECLARE_EVENT_TABLE()
	};

}

#endif
