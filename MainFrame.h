//
// Created by Rasul Mammadov on 29.03.25.
//

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
private:
    void OnClicked(wxCommandEvent& event);
    DECLARE_EVENT_TABLE();
    wxTextCtrl* textCtrl_1;
    wxTextCtrl* textCtrl_2;
    wxListBox* listCtrl;
    wxButton* button;
};



#endif //MAINFRAME_H