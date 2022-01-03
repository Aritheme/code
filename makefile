# 指定源文件目录和头文件目录
dirSrc = ./src
dirHeaders = ./headers
dirOut = ./out
vpath %.h $(dirHeaders)
vpath %.cpp $(dirSrc)

# 指定编译参数
CXX = clang++
# 指定编译选项
CXXFLAGS = -std=c++17 -g
# 给定目标
all:main
# 自动生成文件依赖
# 1.给定需要自动生成依赖的文件
# notdir remove path part in filename
SOURCES =$(wildcard $(dirSrc)/*.cpp)
PURESOURCES =$(notdir $(wildcard $(dirSrc)/*.cpp))
# here we have to add output file directory to filename, otherwise rule main can't find the file
OBJS := $(patsubst %.cpp,%.o,$(addprefix $(dirOut)/, $(PURESOURCES)))
PUREOBJS :=$(notdir $(OBJS))
# 2.用编译器命令生成依赖的文件
%.d : %.cpp
	@set -e; rm -f $@; \
	g++ -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
# 3.包含自动生成的依赖文件
-include $(SOURCES:.cpp=.d)

main : $(PUREOBJS)
	$(CXX) $(CXXFLAGS) -o $(dirOut)/main $(OBJS)
%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) -o $(dirOut)/$@ $<

.PHONY:debug clean

clean :
	@set -e;cd $(dirSrc); rm -f *.d*;
	-@cd $(dirOut);rm -f *.o main;

debug :
	@echo "source files: $(SOURCES)"
	@echo "source files without path: $(PURESOURCES)"
	@echo "obj files: $(OBJS)"
	@echo "obj files without path: $(PUREOBJS)"
