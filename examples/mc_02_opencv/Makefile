# © 2026 : github.com/NMoroney
# MIT License 
#


py :
	python3 px_ocv_distance_transform.py


# SRC=px_ocv_distance_transform
# SRC=px_ocv_distance_transform_17
SRC=px_ocv_distance_transform_23

EXE=distance_transform

OCV=/opt/homebrew/

OCVINC=$(OCV)include/opencv5
OCVLIB=$(OCV)lib

LCORE=-lopencv_core
LCODEC=-lopencv_imgcodecs
LPROC=-lopencv_imgproc

OCVLINK=-L$(OCVLIB) $(LCORE) $(LCODEC) $(LPROC)

# OPT=-std=c++17 -O3 -w
OPT=-std=c++23 -O3 -w


cc :
	g++ $(OPT) $(SRC).cc -I $(OCVINC) $(OCVLINK) -o $(EXE)
	./$(EXE)
