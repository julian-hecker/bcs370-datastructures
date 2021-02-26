#include "Student.h"

int main() {
	Student s("reee", 0.54); // Not a really good semester for reee here
	Student t(s); // copying another student is academic integrity violation
	return 0;
}
