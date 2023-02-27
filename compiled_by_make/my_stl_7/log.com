In file included from test_array.hpp:11,
                 from main.cpp:1:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
In file included from test_array.hpp:11:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
In file included from test_deque.hpp:13:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
In file included from test_forwardlist.hpp:13:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
In file included from test_list.hpp:12:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
In file included from test_multimap.hpp:13:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
In file included from test_multiset.hpp:13:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
In file included from test_vector.hpp:13:
pub.h: In function ‘std::string get_a_target_string()’:
pub.h:36:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
   36 |         snprintf(buf, 10, "%d", target);
      |                            ~^   ~~~~~~
      |                             |   |
      |                             int long int
      |                            %ld
