#include <assert.h>
#include "GenericContainer.h"

using namespace std;

int main(void) {

    GenericContainer<int> myintegers;

    assert(myintegers.is_empty());
}
