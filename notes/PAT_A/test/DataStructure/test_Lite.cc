#include "catch2/catch.hpp"

#include "../../src/DataStructure/Lite.hpp"

using namespace ds::lite;
TEST_CASE("ds::lite usages", "[Lite]") {
  SECTION("StackFn") {
    REQUIRE(StackFn::empty());
    REQUIRE(StackFn::size() == 0);

    StackFn::push(1);
    StackFn::push(2);
    REQUIRE_FALSE(StackFn::empty());
    REQUIRE(StackFn::size() == 2);
    StackFn::clear();
    REQUIRE(StackFn::empty());
    REQUIRE(StackFn::size() == 0);

    StackFn::push(1);
    StackFn::push(2);
    REQUIRE(StackFn::top() == 2);

    StackFn::pop();
    REQUIRE(StackFn::top() == 1);

    while (!StackFn::empty()) StackFn::pop();
    REQUIRE(StackFn::empty());
  }

  SECTION("QueueFn") {
    REQUIRE(QueueFn::empty());
    REQUIRE(QueueFn::size() == 0);

    QueueFn::push(1);
    QueueFn::push(2);
    REQUIRE_FALSE(QueueFn::empty());
    REQUIRE(QueueFn::size() == 2);
    QueueFn::clear();
    REQUIRE(QueueFn::empty());
    REQUIRE(QueueFn::size() == 0);

    QueueFn::push(1);
    QueueFn::push(2);
    QueueFn::push(3);
    REQUIRE(QueueFn::front() == 1);
    REQUIRE(QueueFn::rear() == 3);

    QueueFn::pop();
    REQUIRE(QueueFn::front() == 2);
    REQUIRE(QueueFn::rear() == 3);

    while (!QueueFn::empty()) QueueFn::pop();
    REQUIRE(QueueFn::empty());
  }

  SECTION("LinkedListFn") {
    const int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 8, 8};

    auto* head = LinkedListFn::init(arr, sizeof(arr) / sizeof(int));
    REQUIRE_FALSE(LinkedListFn::empty(head));
    REQUIRE(LinkedListFn::front(head) == 1);

    REQUIRE(LinkedListFn::count(head, 8) == 3);

    LinkedListFn::insert(head, 0, 0);
    REQUIRE(LinkedListFn::front(head) == 0);

    LinkedListFn::remove(head, 8);
    REQUIRE(LinkedListFn::count(head, 8) == 0);
  }
  // SECTION("ArrayFn") {}
}
