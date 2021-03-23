#ifndef upenn_cbica_Recurrence_Activator_h
#define upenn_cbica_Recurrence_Activator_h

#include <ctkPluginActivator.h>

  class RecurrencePluginActivator : public QObject, public ctkPluginActivator
  {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "upenn_cbica_recurrence")
    Q_INTERFACES(ctkPluginActivator)

  public:
    void start(ctkPluginContext *context);
    void stop(ctkPluginContext *context);

    static ctkPluginContext* getContext();

  private:
    static ctkPluginContext* m_Context;
  };


#endif // ! upenn_cbica_Recurrence_Activator_h
