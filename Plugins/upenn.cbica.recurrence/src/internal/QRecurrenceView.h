#ifndef QRecurrenceView_h
#define QRecurrenceView_h

#include <QmitkAbstractView.h>
#include <mitkILifecycleAwarePart.h>

#include "ui_QRecurrenceControls.h"

class QRecurrenceView : public QmitkAbstractView, 
                              public mitk::ILifecycleAwarePart
{
  Q_OBJECT

public:
  static const std::string VIEW_ID;

  QRecurrenceView();
  virtual ~QRecurrenceView();

  // GUI setup
  void CreateQtPartControl(QWidget *parent);

  // ILifecycleAwarePart interface
  void Activated();
  void Deactivated();
  void Visible();
  void Hidden();

protected slots:

  /** \brief "Do Stuff" Button clicked slot */
  void OnDoStuffButtonClicked();

  /** \brief "Run Script" Button clicked slot */
  void OnRunScriptClicked();

protected:

  // reimplemented from QmitkAbstractView
  void OnSelectionChanged(berry::IWorkbenchPart::Pointer part, const QList<mitk::DataNode::Pointer> &nodes) override;

  // reimplemented from QmitkAbstractView
  void OnPreferencesChanged(const berry::IBerryPreferences *prefs) override;

  // reimplemented from QmitkAbstractView
  void NodeAdded(const mitk::DataNode *node) override;

  // reimplemented from QmitkAbstractView
  void NodeRemoved(const mitk::DataNode *node) override;

  void SetFocus();

  void UpdateControls();

  void InitializeListeners();

  /// \brief the Qt parent of our GUI (NOT of this object)
  QWidget *m_Parent;

  /// \brief Qt GUI file
  Ui::QRecurrenceControls m_Controls;


};

#endif // ! QRecurrenceView_h