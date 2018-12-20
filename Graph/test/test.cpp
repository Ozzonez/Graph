#define CATCH_CONFIG_MAIN
#include "test.h"
#include "graph.h"
TEST_CASE(" Does BFS work correctly? ") {
    Graph<int> gr1;
    gr1.testingArguments();
    gr1.bfs(0);
    SECTION("Are sons set correctly?") {
        REQUIRE (gr1.getOneNode(0).getSon() == 2);
        REQUIRE (gr1.getOneNode(0).getSon() == 5);
        REQUIRE (gr1.getOneNode(1).getSon() == 2);
        REQUIRE (gr1.getOneNode(1).getSon() == 3);
        REQUIRE (gr1.getOneNode(2).getSon() == 2);
        REQUIRE (gr1.getOneNode(2).getSon() == 4);
        REQUIRE (gr1.getOneNode(3).getSon() == 1);
        REQUIRE (gr1.getOneNode(4).getSon() == 0);
        REQUIRE (gr1.getOneNode(4).getSon() == 3);
        REQUIRE (gr1.getOneNode(5).getSon() == 1);
    }
}
