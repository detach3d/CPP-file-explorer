//
// Created by Rasul Mammadov on 29.03.25.
//

#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "file_explorer.h"

enum IDs {
    BUTTON_ID = 2
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnClicked)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel *panel = new wxPanel(this);

    button = new wxButton(panel, IDs::BUTTON_ID, wxT("Search"), wxPoint(300, 100), wxSize(200, 50));

    wxStaticText *staticText_1 = new wxStaticText(panel, wxID_ANY, wxT("Filename for search:"), wxPoint(50, 25));
    wxStaticText *staticText_2 = new wxStaticText(panel, wxID_ANY, wxT("Directory:"), wxPoint(300, 25));
    wxStaticText *staticText_3 = new wxStaticText(panel, wxID_ANY, wxT("Result:"), wxPoint(50, 120));
    textCtrl_1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 50), wxSize(200, -1));
    textCtrl_2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 50), wxSize(200, -1));

    listCtrl = new wxListBox(panel, wxID_ANY, wxPoint(50, 150), wxSize(450, 400));
}

void MainFrame::OnClicked(wxCommandEvent &event) {
    listCtrl->Clear();
    const std::string str = textCtrl_1->GetValue().ToStdString();
    file_explorer explorer;

    int b = explorer.file_explore(textCtrl_2->GetValue().ToStdString());
    if (b == 1) {
        for (auto &it: allFiles) {
            //std::cout << it << std::endl;
            listCtrl->AppendString(it);
            event.Skip();
        }
    }else if (b==3) {
        const auto& vec = file_explorer::findFiles(str);
        for (auto &it: vec) {
            //std::cout << it << std::endl;
            listCtrl->AppendString(it);
        }
    }else {
        listCtrl->AppendString("No such file or directory");
    }


    event.Skip();
}
