#include <cstdio>
#include <list>
#include <string>

using Student = std::pair<std::string, int>;

void walkList(std::list<Student>& stu) {
    std::list<Student>::const_iterator it = stu.begin();
    while (it != stu.end()) {
        printf("Student = %10s\tAge = %d\n", it->first.c_str(), it->second);
        ++it;
    }
}

int main() {
    /**
     * We have the options of push_back and push_front with list container class
     */
    std::list<Student> Students;
    Students.push_back(std::make_pair("alice", 23));
    Students.push_back(std::make_pair("jason", 25));
    Students.push_back(std::make_pair("bob", 20));
    Students.push_back(std::make_pair("russel", 24));

    Students.push_front(Student{"keith", 24});
    walkList(Students);
    Students.reverse();
    printf("\n");
    walkList(Students);
    return 0;
}
