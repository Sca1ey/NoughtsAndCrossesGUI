// wxWidgets "Hello World" Program
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
};

// Declare an ID for the Reset event
enum
{
   ID_Reset = 1
};

// Initialise the App and call MyFrame 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
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
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(new wxButton(this,wxID_ANY,""),wxSizerFlags().Align(wxALIGN_CENTER));
        
    this->SetSizer(grid);
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

