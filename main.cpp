// wxWidgets "Noughts and Crosses"

// Include the Noughts and Crosses game class and enum
#include "game.cpp"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

// Create the app 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// Declare the Frame Class, constructor and event handlers
class MyFrame : public wxFrame
{
public:
    MyFrame();
 
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void Button1(wxCommandEvent& event);
    void Button2(wxCommandEvent& event);
    void Button3(wxCommandEvent& event);
    void Button4(wxCommandEvent& event);
    void Button5(wxCommandEvent& event);
    void Button6(wxCommandEvent& event);
    void Button7(wxCommandEvent& event);
    void Button8(wxCommandEvent& event);
    void Button9(wxCommandEvent& event);  
};

// Declare IDs for the events
enum
{
   ID_Button1 = 1,
   ID_Button2 = 2,
   ID_Button3 = 3,
   ID_Button4 = 4,
   ID_Button5 = 5,
   ID_Button6 = 6,
   ID_Button7 = 7,
   ID_Button8 = 8,
   ID_Button9 = 9,
   ID_Reset = 10
};

// Initialise the App and call MyFrame 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);

    Game *game = new Game;

    return true;
}

// Define the contents of the MyFrame in its constructor
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Noughts and Crosses",wxDefaultPosition,wxSize(450,400))
{
    //File menu
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Reset, "&Reset\tCtrl-R",
                     "Reset the game!");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    //Help Menu
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
        
    //Add menus to menu bar
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );
 
    //Status bar
    CreateStatusBar();
    SetStatusText("Welcome to Noughts and Crosses.");

    //Bind event handlers for menu 
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Reset);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    //Add Button Grid
    wxGridSizer *grid = new wxGridSizer(3,1,1);
    grid->Add(new wxButton(this,ID_Button1,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button2,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button3,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button4,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button5,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button6,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button7,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button8,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,ID_Button9,""),wxSizerFlags().Align(wxALIGN_CENTER));
        
    this->SetSizer(grid);

    //Bind event handlers for buttons
    Bind(wxEVT_BUTTON, &MyFrame::Button1, this, ID_Button1);
    Bind(wxEVT_BUTTON, &MyFrame::Button2, this, ID_Button2);
    Bind(wxEVT_BUTTON, &MyFrame::Button3, this, ID_Button3);
    Bind(wxEVT_BUTTON, &MyFrame::Button4, this, ID_Button4);
    Bind(wxEVT_BUTTON, &MyFrame::Button5, this, ID_Button5);
    Bind(wxEVT_BUTTON, &MyFrame::Button6, this, ID_Button6);
    Bind(wxEVT_BUTTON, &MyFrame::Button7, this, ID_Button7);
    Bind(wxEVT_BUTTON, &MyFrame::Button8, this, ID_Button8);
    Bind(wxEVT_BUTTON, &MyFrame::Button9, this, ID_Button9);
    
}

// Define Event handlers 
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets version of Noughts and Crosses",
                 "About Noughts and Crosses", wxOK | wxICON_INFORMATION);
}
 
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("TODO: Reset the Game!");
}

void MyFrame::Button1(wxCommandEvent& event)
{
    SetStatusText("Button1");
}

void MyFrame::Button2(wxCommandEvent& event)
{
    SetStatusText("Button2");
}

void MyFrame::Button3(wxCommandEvent& event)
{
    SetStatusText("Button3");
}

void MyFrame::Button4(wxCommandEvent& event)
{
    SetStatusText("Button4");
}

void MyFrame::Button5(wxCommandEvent& event)
{
    SetStatusText("Button5");
}

void MyFrame::Button6(wxCommandEvent& event)
{
    SetStatusText("Button6");
}

void MyFrame::Button7(wxCommandEvent& event)
{
    SetStatusText("Button7");
}

void MyFrame::Button8(wxCommandEvent& event)
{
    SetStatusText("Button8");
}

void MyFrame::Button9(wxCommandEvent& event)
{
    SetStatusText("Button9");
}