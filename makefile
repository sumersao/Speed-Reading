CC = g++
FLAGS = --std=c++17 -Wall -Werror -Wpedantic -O1
LDLIBS = -lcurl
CPP_FILES = test.cpp get_article.cpp

all: test

test: $(CPP_FILES)
	$(CC) $(FLAGS) $^ -o $@ $(LDLIBS)

server:
	cd article-server && \
		npm install && \
		bash -c "npm start &"
