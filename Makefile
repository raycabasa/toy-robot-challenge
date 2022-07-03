TARGET = ToyRobotApp

CXX = g++
CFLAGS = -g -Wall -std=c++17 -I${HEADERS}

HEADERS := include/

APP_SOURCE = app/ToyRobotApp.cpp

SOURCES := Command.cpp \
		   Coordinate.cpp \
		   Direction.cpp \
		   Position.cpp \
		   Table.cpp \
		   ToyRobot.cpp \

${TARGET}: ${SOURCES}
	${CXX} ${CFLAGS} -o ${TARGET} ${SOURCES} ${APP_SOURCE}

TEST = ToyRobotTest

TEST_CODES := test/toyrobottest.cpp

${TEST} : ${SOURCES} ${TEST_CODES}
	${CXX} ${CFLAGS} -o ${TEST} ${SOURCES} ${TEST_CODES}

all: clean ${TARGET} ${TEST}

test: ${TEST}
	./${TEST}

clean:
	rm -rf ${TARGET} ${TEST}

