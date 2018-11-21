
# add files you create here
OBJ = IntInf.o example.o StringList.o StringArrayList.o PList.o
all: libece309.a

test: all

# add files you want to remove here
clean:
	rm -f *~ libece309.a $(OBJ)

libece309.a: $(OBJ)
	$(AR) -r $@ $(OBJ) 

%.o:%.cpp
	$(CXX) -c -o $@ -I . -I ../include $< -Wall -Werror -std=c++11
