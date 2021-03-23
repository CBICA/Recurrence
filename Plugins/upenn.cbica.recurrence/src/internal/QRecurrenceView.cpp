#include "QRecurrenceView.h"

#include <QMessageBox>

const std::string QRecurrenceView::VIEW_ID =
    "upenn.cbica.recurrence.view";


QRecurrenceView::QRecurrenceView()
{
  // ---- General setup operations ----
}

QRecurrenceView::~QRecurrenceView()
{

}

void QRecurrenceView::CreateQtPartControl(QWidget *parent)
{
  // ---- Setup the basic GUI of this view ----
  m_Parent = parent;
  m_Controls.setupUi(parent);

  connect(m_Controls.pushButton_DoStuff, SIGNAL(clicked()),
	  this, SLOT(OnDoStuffButtonClicked()));
 
}

void QRecurrenceView::Activated()
{
  // Not yet implemented
}

void QRecurrenceView::Deactivated()
{
  // Not yet implemented
}

void QRecurrenceView::Visible()
{
  // Not yet implemented
}

void QRecurrenceView::Hidden()
{
  // Not yet implemented
}

/************************************************************************/
/* protected slots                                                      */
/************************************************************************/

void QRecurrenceView::OnDoStuffButtonClicked()
{
    QMessageBox msgError;
    msgError.setText("Hello, I am Recurrence.");
    msgError.setIcon(QMessageBox::Critical);
    msgError.setWindowTitle("Recurrence");
    msgError.exec();
}

/************************************************************************/
/* protected                                                            */
/************************************************************************/

void QRecurrenceView::OnRunScriptClicked()
{
	MITK_INFO << "  script button clicked ";
}

void QRecurrenceView::OnSelectionChanged(berry::IWorkbenchPart::Pointer, const QList<mitk::DataNode::Pointer>& /*nodes*/)
{

}

void QRecurrenceView::OnPreferencesChanged(const berry::IBerryPreferences* /*prefs*/)
{

}

void QRecurrenceView::NodeAdded(const mitk::DataNode* /*node*/)
{

}

void QRecurrenceView::NodeRemoved(const mitk::DataNode* /*node*/)
{

}

void QRecurrenceView::SetFocus()
{

}

void QRecurrenceView::UpdateControls()
{
  // Here you can hide views that are not useful and more
}

void QRecurrenceView::InitializeListeners()
{

}