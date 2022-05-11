g++ -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic  -O3 -DNDEBUG -c stackQueue.cpp
g++ -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic  -O3 -DNDEBUG -c main.cpp
g++ -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic  -O3 -DNDEBUG stackQueue.o main.o -o superMarco
