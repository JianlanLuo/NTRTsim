/*
 * Copyright © 2012, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All rights reserved.
 * 
 * The NASA Tensegrity Robotics Toolkit (NTRT) v1 platform is licensed
 * under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0.
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language
 * governing permissions and limitations under the License.
*/

/**
 * @file tgPairs.h
 * @brief Definition of class tgPairs 
 * @author Ryan Adams
 * @date March 2014
 * $Id$
 */


/*
Adding nameability to pairs
- Add pair overloading (addNamedPair)
- [] operator using strings for names
+ pairNameExists(name)
- RemovePair
- '-' operator
x getPair (getNamedPair?) -- using [] overloading instead
- setPair (setNamedPair?)
- copy constructor (should also copy name->index mapping)
- getPairKey(name) 
- assertNameExists(name);
*/

#ifndef TG_PAIRS_H
#define TG_PAIRS_H

#include <string>
#include <vector>
#include <algorithm>    // std::find, std::remove
#include "core/tgComponentList.h"
#include "tgPair.h"
#include "tgUtil.h"

class tgPairs : public tgComponentList<tgPair>
{
public:
    
    // @todo: do we need to initialize the pairs here?
    tgPairs() : tgComponentList() {}
    
    // tgPairs(std::vector<tgPair>& pairs) : tgComponentList(pairs) { // @todo: Fix this -- casting is a problem...
    tgPairs(std::vector<tgPair>& pairs) : tgComponentList() {
        // @todo: make sure each pair is unique
        for(std::size_t i = 0; i < pairs.size(); i++) {
            addElement(pairs[i]);
        }
    }

    ~tgPairs() {}

    std::vector<tgPair>& getPairs()
    {
        return getElements();
    }

    const std::vector<tgPair>& getPairs() const
    {
        return getElements();
    }

    int addPair(const tgPair& pair) {
        // @todo: make sure the pair is unique (both ways -- (a.from != b.from && a.to != b.to) && (a.from != b.to && a.to != b.from) )
        return addElement(pair);
    }

    int addPair(tgPair pair, const tgTags& tags)
    {
        pair.addTags(tags);
        return addPair(pair);
    }

    int addPair(tgPair pair, const std::string& space_separated_tags)
    {
        pair.addTags(space_separated_tags);
        return addPair(pair);
    }

    /* // temporarily disabled until tgComponentList supports addNamedElement
    int addNamedPair(const std::string& name, tgPair pair)
    {
        return addNamedElement(name, pair);
    }

    int addNamedPair(const std::string& name, tgPair pair, const tgTags& tags)
    {
        pair.addTags(tags);
        return addNamedPair(name, pair);
    }

    int addNamedPair(const std::string& name, tgPair pair, const std::string& space_separated_tags)
    {
        pair.addTags(space_separated_tags);
        return addNamedPair(name, pair);
    }
    */
    
    void setPair(int key, tgPair pair) {
        setElement(key, pair);
    }

    void move(const btVector3& offset)
    {
        std::vector<tgPair>& pairs = getPairs();
        for(std::size_t i = 0; i < pairs.size(); i++) {
            pairs[i].move(offset);
        }
    }

    void addRotation(const btVector3& fixedPoint,
                     const btVector3& axis,
                     double angle)
    {
        btQuaternion rotation(axis, angle);
        addRotation(fixedPoint, rotation);
    }

    void addRotation(const btVector3& fixedPoint,
                     const btVector3& fromOrientation,
                     const btVector3& toOrientation)
    {
        btQuaternion rotation = tgUtil::getQuaternionBetween(fromOrientation, 
                                                             toOrientation);
        addRotation(fixedPoint, rotation);
    }

    void addRotation(const btVector3& fixedPoint,
                     const btQuaternion& rotation)
    {
        std::vector<tgPair>& pairs = getPairs();
        for(std::size_t i = 0; i < pairs.size(); i++) {
            pairs[i].addRotation(fixedPoint, rotation);
        }
    }


    /**
     * Return the complement of this and other
     */
    /*
    // @note: Removed until we can refactor tgComponentList to handle removal
    // of elements gracefully. 
    tgPairs& operator-=(const tgPairs& other) {
        this->removeElements(other.getElements());
        return *this;
    }

    tgPairs& operator-=(const std::vector<tgPair*> other) {
        this->removeElements(other);
        return *this;
    }
    */

};

/*
// @note: disabled until tgComponentList can handle removal of named elements
inline tgPairs operator-(tgPairs lhs, const tgPairs& rhs)
{
    lhs -= rhs;
    return lhs;
}

inline tgPairs operator-(tgPairs lhs, const std::vector<tgPair*>& rhs)
{
    lhs -= rhs;
    return lhs;
}
*/

/**
 * Overload operator<<() to handle tgPairs
 * @param[in,out] os an ostream
 * @param[in] p a tgPairs
 * @return os
 * @todo Inlining this does no good; stream operations are slow.
 */
inline std::ostream&
operator<<(std::ostream& os, const tgPairs& p)
{

    os << "tgPairs(" << std::endl;
    const std::vector<tgPair>& pairs = p.getPairs();
    for(std::size_t i = 0; i < pairs.size(); i++) {
        os << "  " << pairs[i] << std::endl;
    }
    os << ")";

    return os;
}

#endif
