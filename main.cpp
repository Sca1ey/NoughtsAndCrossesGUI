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

// Declare the Frame Class, constructor and event handler methods
class MyFrame : public wxFrame
{
public:
    MyFrame();
 
private:
    void OnReset(wxCommandEvent& event);
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

//Create an id for the Reset menu option
enum {
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
        
    //Add menubar to frame
    SetMenuBar( menuBar );
 
    //Create Status bar and set inital text
    CreateStatusBar();
    int currPlayer = 1;
    SetStatusText("Player 1's turn.");

    //Bind event handlers for menu 
    Bind(wxEVT_MENU, &MyFrame::OnReset, this, ID_Reset);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    //Create GridSizer and buttons
    wxGridSizer *grid = new wxGridSizer(3,1,1);
    wxButton *button1 = new wxButton(this, wxID_ANY,"");
    wxButton *button2= new wxButton(this, wxID_ANY,"");
    wxButton *button3= new wxButton(this, wxID_ANY,"");
    wxButton *button4= new wxButton(this, wxID_ANY,"");
    wxButton *button5= new wxButton(this, wxID_ANY,"");
    wxButton *button6= new wxButton(this, wxID_ANY,"");
    wxButton *button7= new wxButton(this, wxID_ANY,"");
    wxButton *button8= new wxButton(this, wxID_ANY,"");
    wxButton *button9= new wxButton(this, wxID_ANY,"");

    //Add buttons to grid    
    grid->Add(button1, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button2, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button3, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button4, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button5, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button6, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button7, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button8, wxSizerFlags().Align(wxALIGN_CENTER));
    grid->Add(button9, wxSizerFlags().Align(wxALIGN_CENTER));
    
    //Add grid to frame
    this->SetSizer(grid);

    //Bind event handlers for buttons
    button1->Bind(wxEVT_BUTTON, &MyFrame::Button1, this);
    button2->Bind(wxEVT_BUTTON, &MyFrame::Button2, this);
    button3->Bind(wxEVT_BUTTON, &MyFrame::Button3, this);
    button4->Bind(wxEVT_BUTTON, &MyFrame::Button4, this);
    button5->Bind(wxEVT_BUTTON, &MyFrame::Button5, this);
    button6->Bind(wxEVT_BUTTON, &MyFrame::Button6, this);
    button7->Bind(wxEVT_BUTTON, &MyFrame::Button7, this);
    button8->Bind(wxEVT_BUTTON, &MyFrame::Button8, this);
    button9->Bind(wxEVT_BUTTON, &MyFrame::Button9, this);    
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
 
void MyFrame::OnReset(wxCommandEvent& event)
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