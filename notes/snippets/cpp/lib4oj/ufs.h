#pragma once

namespace oj {
namespace sets {

void ufs_init();
int ufs_find_father(int x);
int ufs_find_father_recursive(int x);
int ufs_find_father_zip(int x);
int ufs_find_father_zip_recursive(int x);
void ufs_union(int a, int b);

}  // namespace sets
}  // namespace oj

#include "impl/ufs.cpp"