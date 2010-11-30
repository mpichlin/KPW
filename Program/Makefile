APP=ThesauriDesigner
START=./$(APP) &
SRC=src/*.cpp UI_HEADERS_DIR=./ui/inc
INC=inc/*.hpp
OBJ=./obj
PODSTAWIENIA=OBJECTS_DIR=$(OBJ) MOC_DIR=$(MOC) QT+=opengl \
	 CONFIG+=qt CONFIG+=link_pkgconfig  PKGCONFIG+=soprano 
#DEFINES+=QT_NO_DEBUG_OUTPUT <- switch off QDebug
MOC=./moc
FORMS=ui/*.ui
__start__ : $(APP)
	rm -f core*; $(START)
$(APP): Makefile.app __sprawdz__
__sprawdz__ : 
	make -f Makefile.app 
Makefile.app: $(APP).pro
	qmake-qt4 -o Makefile.app $(APP).pro

$(APP).pro: clean 
	qmake-qt4 -project -o $(APP).pro $(PODSTAWIENIA) $(SRC) $(INC)
clean:
	rm -f $(APP).pro Makefile.app $(APP)*
rmobj:
	rm -f $(OBJ)/*.o $(APP)*
