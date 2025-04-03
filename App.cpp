//
// Created by Rasul Mammadov on 29.03.25.
// App.cpp
#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include <memory>
#include "file_explorer.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    //file_explorer f;
    MainFrame* mainFrame = new MainFrame("C++ GUI");
    mainFrame->SetClientSize(wxSize(550, 600));
    mainFrame->Center();
    mainFrame->Show();
    return true;
}