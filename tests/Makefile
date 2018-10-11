
# list the name of each file (without the .cpp file at the end)
EXE = example PList IntegerSetArray_test IntArray_test

all: $(EXE)

run: all $(addsuffix -run,$(EXE))

clean:
	rm -f $(EXE) *~ logfile.txt $(ECE)

%: %.cpp
	$(CXX) -o $@ $< -Wall -Werror -I ../include -L ../lib -lece309

%-run:
	@./$*

