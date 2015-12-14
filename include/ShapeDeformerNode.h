#ifndef PUSH_DEFORMER_NODE
#define PUSH_DEFORMER_NODE

#include <math.h>

#include <maya/MTime.h>
#include <maya/MAnimControl.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MGlobal.h>
#include <maya/MItGeometry.h>
#include <maya/MMatrix.h>
#include <maya/MPointArray.h>
#include <maya/MStatus.h>

#include <maya/MFnMesh.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFloatVectorArray.h>

#include <maya/MPxDeformerNode.h>

#include "../include/ParticleSystem.h"

// Simple deformer node
class ShapeDeformerNode : public MPxDeformerNode {

public:
    ShapeDeformerNode() {}
    virtual MStatus deform(MDataBlock& data, MItGeometry& itGeo,
                         const MMatrix &localToWorldMatrix, unsigned int mIndex);
    static void* creator();
    static MStatus initialize();
    // Unique id
    static MTypeId id;

    // Attributes (a as in attribute on variable names)
    // Global attributes
    static MObject aGravityMagnitude;
    static MObject aGravityDirection;

    // Object attributes from rigid body
    static MObject aCurrentTime;
    static MObject aMass;
    static MObject aStiffness;
    static MObject aElasticity;
    static MObject aStaticFriction;
    static MObject aDynamicFriction;

private:
    static ParticleSystem* ps;
    static bool firstFrame;
    static MTime tPrevious;
};

#endif