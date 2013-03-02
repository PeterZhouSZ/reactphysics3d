/********************************************************************************
* ReactPhysics3D physics library, http://code.google.com/p/reactphysics3d/      *
* Copyright (c) 2010-2013 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/

 // Libraries
#include "CollisionBody.h"

// We want to use the ReactPhysics3D namespace
using namespace reactphysics3d;

// Constructor
CollisionBody::CollisionBody(const Transform& transform, CollisionShape *collisionShape,
                             bodyindex id)
    : Body(id), mCollisionShape(collisionShape), mTransform(transform),
      mIsActive(true), mHasMoved(false) {

    assert(collisionShape);

    mIsMotionEnabled = true;
    mIsCollisionEnabled = true;
    mInterpolationFactor = 0.0;

    // Initialize the old transform
    mOldTransform = transform;

    // Create the AABB for broad-phase collision detection
    mAabb = new AABB(transform, collisionShape->getLocalExtents(OBJECT_MARGIN));
}

// Destructor
CollisionBody::~CollisionBody() {

    // Delete the AABB
    delete mAabb;
}