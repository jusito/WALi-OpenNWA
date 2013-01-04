#include <glog/logging.h>
#include "gtest/gtest.h"
#include "wali/util/DisjointSets.hpp"

#include <string>

namespace wali {
    namespace util {     
        
        template class DisjointSets<std::string>;

        typedef DisjointSets<std::string> StringSets;
        typedef std::vector<std::set<std::string> > StringMatrix;


        bool
        disjoint_sets_equal_matrix(StringMatrix const & expected,
                                   StringSets const & sets)
        {
            StringMatrix actual;
            for(StringSets::const_iterator outer_iter = sets.begin();
                outer_iter != sets.end(); ++outer_iter)
            {
                std::set<std::string> actual_row(outer_iter->begin(),
                                                 outer_iter->end());
                actual.push_back(actual_row);
            }
            
            if (actual.size() != expected.size()) {
#if 0
                std::cout << std::flush;
                std::cerr << "actual and expected have different sizes (" << actual.size() << " vs " << expected.size() << ")\n";
                std::cerr << "    actual = {\n";
                for(StringSets::const_iterator outer_iter = sets.begin();
                    outer_iter != sets.end(); ++outer_iter)
                {
                    std::cerr << "        {";
                    for(StringSets::InnerSet::const_iterator inner_iter = outer_iter->begin();
                        inner_iter != outer_iter->end(); ++inner_iter)
                    {
                        std::cerr << *inner_iter << ", ";
                    }
                    std::cerr << "}\n";
                }
                std::cerr << "    }\n";
#endif
                return false;
            }
            
            for(StringMatrix::const_iterator outer_iter = actual.begin();
                outer_iter != actual.end(); ++outer_iter)
            {
                if (std::find(expected.begin(),
                              expected.end(),
                              *outer_iter)
                    == expected.end())
                {
                    return false;
                }
            }

            return true;
        }
        

        TEST(wali$util$DisjointSets, emptyCollectionIsEmpty)
        {
            StringSets sets;
            EXPECT_EQ(sets.begin(), sets.end());
        }


        TEST(wali$util$DisjointSets, addingUnconnectedElementsAddsThem)
        {
            StringSets sets;

            sets.insert("a");
            sets.insert("b");

            StringMatrix expected;
            expected.resize(2);
            expected[0].insert("a");
            expected[1].insert("b");

            EXPECT_TRUE(disjoint_sets_equal_matrix(expected, sets));
        }

        TEST(wali$util$DisjointSets, notAddingElementsDoesntAddThem)
        {
            StringSets sets;

            sets.insert("a");

            StringMatrix expected;
            expected.resize(2);
            expected[0].insert("a");
            expected[1].insert("b");

            EXPECT_FALSE(disjoint_sets_equal_matrix(expected, sets));
        }

        TEST(wali$util$DisjointSets, mergeTwoSingletons)
        {
            StringSets sets;

            sets.insert("a");
            sets.insert("b");
            sets.merge_sets("a", "b");

            StringMatrix expected;
            expected.resize(1);
            expected[0].insert("a");
            expected[0].insert("b");

            EXPECT_TRUE(disjoint_sets_equal_matrix(expected, sets));
        }


        TEST(wali$util$DisjointSets, largerTest)
        {
            StringSets sets;

            sets.insert("a");
            sets.insert("b");
            sets.insert("c");
            sets.insert("d");
            sets.insert("e");
            sets.insert("f");
            sets.insert("g");
            sets.merge_sets("a", "b");
            sets.merge_sets("c", "d");
            sets.merge_sets("a", "d");
            sets.merge_sets("a", "d");
            sets.merge_sets("e", "f");

            StringMatrix expected;
            expected.resize(3);
            expected[0].insert("a");
            expected[0].insert("b");
            expected[0].insert("c");
            expected[0].insert("d");
            expected[1].insert("e");
            expected[1].insert("f");
            expected[2].insert("g");

            EXPECT_TRUE(disjoint_sets_equal_matrix(expected, sets));
        }


        TEST(wali$util$DisjointSets, copyConstructor)
        {
            StringSets sets1;
            sets1.insert("a");
            sets1.insert("b");

            StringSets sets2 = sets1;
            sets2.insert("c");
            sets2.merge_sets("a", "c");

            StringMatrix expected1;
            expected1.resize(2);
            expected1[0].insert("a");
            expected1[1].insert("b");

            StringMatrix expected2;
            expected2.resize(2);
            expected2[0].insert("a");
            expected2[1].insert("b");
            expected2[0].insert("c");

            EXPECT_TRUE(disjoint_sets_equal_matrix(expected1, sets1));
            EXPECT_TRUE(disjoint_sets_equal_matrix(expected2, sets2));
        }
    }
}

// Yo, Emacs!
// Local Variables:
//   c-file-style: "ellemtel"
//   c-basic-offset: 4
// End:
