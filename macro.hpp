//
// Created by fx on 22/8/2562.
//

#ifndef LINE_FOLLOWER_MACRO_HPP
#define LINE_FOLLOWER_MACRO_HPP


typedef uint64_t fime_t;
template <typename type>
type sign(type value) {
    return type((value>0)-(value<0));
}


#endif //LINE_FOLLOWER_MACRO_HPP
