#include "MainFrame.h"
#include <wx/wx.h>

// Define the contents of the Frame in its constructor
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{     
    //Frame::CreateMenus();
    //Frame::CreateControls();
    //Frame::BindEventHandlers();
}

/*
void Frame::CreateMenus()
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
    int currPlayer = wxGetApp().game->getPlayer();
    SetStatusText(wxString::Format(wxT("Player %d's turn."),currPlayer));
}

void Frame::CreateControls()
{
    //Create GridSizer
    grid = new wxGridSizer(3,1,1);
    this->SetSizer(grid);
    
    //create buttons
    button1 = new wxButton(grid, wxID_ANY,"");
    button2 = new wxButton(grid, wxID_ANY,"");
    button3 = new wxButton(grid, wxID_ANY,"");
    button4 = new wxButton(grid, wxID_ANY,"");
    button5 = new wxButton(grid, wxID_ANY,"");
    button6 = new wxButton(grid, wxID_ANY,"");
    button7 = new wxButton(grid, wxID_ANY,"");
    button8 = new wxButton(grid, wxID_ANY,"");
    button9 = new wxButton(grid, wxID_ANY,"");
    
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
}

void Frame::BindEventHandlers()
{
    //Bind event handlers for menu 
    Bind(wxEVT_MENU, &Frame::OnReset, this, wxID_ANY);
    Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
    
    //Bind event handlers for buttons
    button1->Bind(wxEVT_BUTTON, &Frame::Button1, this);
    button2->Bind(wxEVT_BUTTON, &Frame::Button2, this);
    button3->Bind(wxEVT_BUTTON, &Frame::Button3, this);
    button4->Bind(wxEVT_BUTTON, &Frame::Button4, this);
    button5->Bind(wxEVT_BUTTON, &Frame::Button5, this);
    button6->Bind(wxEVT_BUTTON, &Frame::Button6, this);
    button7->Bind(wxEVT_BUTTON, &Frame::Button7, this);
    button8->Bind(wxEVT_BUTTON, &Frame::Button8, this);
    button9->Bind(wxEVT_BUTTON, &Frame::Button9, this);
}

void Frame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets version of Noughts and Crosses",
    "About Noughts and Crosses", wxOK | wxICON_INFORMATION);
}

void Frame::OnReset(wxCommandEvent& event)
{
    wxGetApp().game->initBoard();
    button1->SetLabel("");
}

void Frame::PlaySquare(wxButton* button, int x, int y)
{
    if(wxGetApp().game->getPosition(x,y) == 0){
        wxGetApp().game->setPosition(x,y,wxGetApp().game->getPlayer());
        
        int currPlayer = wxGetApp().game->getPlayer();
        char buttonLabel;
        if(currPlayer == 1){buttonLabel = 'O';} else {buttonLabel = 'X';};
        button->SetLabel(buttonLabel);
        
        if(wxGetApp().game->checkWin() == true){
            wxMessageBox(wxString::Format(wxT("Player %d Wins!"),currPlayer));
            SetStatusText("Reset to play again.");
        } else {   
            int nextPlayer = wxGetApp().game->switchPlayer();
        SetStatusText(wxString::Format(wxT("Player %d's turn."),nextPlayer));
    }
};


}

void Frame::Button1(wxCommandEvent& event)
{   
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 0, 0);
}

void Frame::Button2(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 1, 0);
}

void Frame::Button3(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 2, 0);
}

void Frame::Button4(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 0, 1);
}

void Frame::Button5(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 1, 1);
}

void Frame::Button6(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 2, 1);
}

void Frame::Button7(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 0, 2);
}

void Frame::Button8(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 1, 2);
}

void Frame::Button9(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    Frame::PlaySquare(button, 2, 2);
}
*/