/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
* Copyright (c) 2013 Google, Inc.
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef BOX2D_H
#define BOX2D_H

/**
\mainpage LiquidFun API Documentation

*/

// These include files constitute the main box2d API

#include <box2d/common/b2Settings.h>
#include <box2d/common/b2Draw.h>
#include <box2d/common/b2Stat.h>
#include <box2d/common/b2Timer.h>

#include <box2d/collision/shapes/b2CircleShape.h>
#include <box2d/collision/shapes/b2EdgeShape.h>
#include <box2d/collision/shapes/b2ChainShape.h>
#include <box2d/collision/shapes/b2PolygonShape.h>

#include <box2d/collision/b2BroadPhase.h>
#include <box2d/collision/b2Distance.h>
#include <box2d/collision/b2DynamicTree.h>
#include <box2d/collision/b2TimeOfImpact.h>

#include <box2d/dynamics/b2Body.h>
#include <box2d/dynamics/b2Fixture.h>
#include <box2d/dynamics/b2WorldCallbacks.h>
#include <box2d/dynamics/b2TimeStep.h>
#include <box2d/dynamics/b2World.h>

#include <box2d/dynamics/contacts/b2Contact.h>

#include <box2d/dynamics/joints/b2DistanceJoint.h>
#include <box2d/dynamics/joints/b2FrictionJoint.h>
#include <box2d/dynamics/joints/b2GearJoint.h>
#include <box2d/dynamics/joints/b2MotorJoint.h>
#include <box2d/dynamics/joints/b2MouseJoint.h>
#include <box2d/dynamics/joints/b2PrismaticJoint.h>
#include <box2d/dynamics/joints/b2PulleyJoint.h>
#include <box2d/dynamics/joints/b2RevoluteJoint.h>
#include <box2d/dynamics/joints/b2RopeJoint.h>
#include <box2d/dynamics/joints/b2WeldJoint.h>
#include <box2d/dynamics/joints/b2WheelJoint.h>

#include <box2d/particle/b2Particle.h>
#include <box2d/particle/b2ParticleGroup.h>

#endif
