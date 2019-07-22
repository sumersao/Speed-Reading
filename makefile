CC = g++
CPP_FLAGS = --std=c++17 -Wall -Werror -Wpedantic -O1 -g
LDLIBS = -lcurl
CPP_FILES = segmentation.cpp get_article.cpp

all: test

test: $(CPP_FILES)
	$(CC) $^ -o $@ $(LDLIBS)

server:
	cd article-server && \
		npm install && \
		bash -c "npm start &"
