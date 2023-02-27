lecture.cpp: In function ‘void yao01::test_member_template()’:
lecture.cpp:41:30: warning: parentheses were disambiguated as a function declaration [-Wvexing-parse]
   41 |         pair<Base1, Base2> p2(pair<Derived1, Derived2>());
      |                              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
lecture.cpp:41:30: note: replace parentheses with braces to declare a variable
   41 |         pair<Base1, Base2> p2(pair<Derived1, Derived2>());
      |                              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                              -
      |                              {                          -
      |                                                         }
lecture.cpp: In function ‘void yao03::test_template_template_parameters_2()’:
lecture.cpp:111:22: warning: ‘template<class> class std::auto_ptr’ is deprecated [-Wdeprecated-declarations]
  111 |         XCLS<double, auto_ptr> p4;
      |                      ^~~~~~~~
In file included from /usr/include/c++/11/memory:76,
                 from lecture.cpp:12:
/usr/include/c++/11/bits/unique_ptr.h:57:28: note: declared here
   57 |   template<typename> class auto_ptr;
      |                            ^~~~~~~~
