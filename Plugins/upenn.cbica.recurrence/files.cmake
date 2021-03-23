set(SRC_CPP_FILES
  
)

set(INTERNAL_CPP_FILES
  RecurrencePluginActivator.cpp
  QRecurrenceView.cpp
)

set(UI_FILES
  src/internal/QRecurrenceControls.ui
)

set(MOC_H_FILES
  src/internal/RecurrencePluginActivator.h
  src/internal/QRecurrenceView.h
)

set(CACHED_RESOURCE_FILES
  resources/icon1.svg
  plugin.xml
)

set(QRC_FILES

)

### Don't change below

set(CPP_FILES)

foreach(file ${SRC_CPP_FILES})
  set(CPP_FILES ${CPP_FILES} src/${file})
endforeach(file ${SRC_CPP_FILES})

foreach(file ${INTERNAL_CPP_FILES})
  set(CPP_FILES ${CPP_FILES} src/internal/${file})
endforeach(file ${INTERNAL_CPP_FILES})
