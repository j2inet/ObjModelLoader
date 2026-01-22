# OBJ Model Loader

This is my take on loading a subset of the OBJ model format. The OBJ format for 3D models was
developer by WaveFront for interoperability. WaveFront was later acquired by Autodesk. This source
is not meant to load all possible constructs that can be found in an OBJ file. 

Written by Joel Ivory Johnson

# Specification Source

I looked at several sources and decided on this document as a spec to build from. 

https://paulbourke.net/dataformats/obj/obj_spec.pdf

# Why Am I Doing This?

I'm no stranger to working with 3D assets. Normally, I'm consuming them in another tool, such as Unit, which has native support for them. The
software tools are able to parse the file, load the model into some object, and then I'm able to perform high-level operations on the object 
such as instancing, replacating, translating, scaling, so on. But what if I need to consume the information myself for some operation? I need
to be able to parse the information myself. 

Among the many popular specifications for encoding 3D model information is the OBJ format. It was originally made by a company known as WaveFront
in the interest of promoting interoperability among 3D programs. WaveFront was later acquired by AutoDesk. The format has been around for a while, 
is widely supported, and from a quick glance at the spec, it looks to be an easy format to parse out. 

# About the Vertex Format

VERTEX formats may be completely custom formats. When I parse the information, it must be loaded into some structure. I wanted the parser to be free 
of any specific vertex format. But that's inescapable. I decided on a vertex that holds a 3D point, 2D texture coordinate, a 3D vector normal,  and some 
flags to specify whether the data in the texture and normal fields are valid. 

# Implemented OBJ Features

I checked for the features that could be encoded within a .obj file. While the number of features looks intimidating at first, once I realized that 
the 3D exports that I have do not use all the features, I realized I could move forward writing this and not have to implement all OBJ file
features on the first pass. 

The data in OBJ files is organized into lines. .The first item of data on the line specifies the type of data that the line will contain. The data
type is communicated with a short string of a few  letters. For some simple renders, I found that these were the most important line types to know.		

* v - 3D vertex
* vn - 3D vertex normal
* vt - 2D texture coordinate
* f - face
* usmtl - name of material to apply
* mtlib - the name of the material description file to apply

- [x] (v) geometric verticies
- [x] (vt) texture vertices
- [x] (vn) vertex normals
- [ ] (vp) parameter space vertices
- [ ] (cstype) basis matrix, Bezier, B-spline, Cardinal, Taylor
- [ ] (deg) Degree
- [ ] (bmat) Basis Matrix
- [ ] (step) Step Size
- [ ] (p) Point
- [ ] (l) line
- [x] (f) Face
- [ ] (curv) curve
- [ ] (curv2) 2D Curve
- [ ] (surf) Surface
- [ ] (param) Parameter value
- [ ] (trim) Outer Trim Loop
- [ ] (hole) inner trimmint loop
- [ ] (scrv) special curve
- [ ] (sp) special point
- [ ] (end) end statement
- [ ] (con) connect
- [ ] (g) group name
- [x] (s) smoothing group
- [ ] (bevel) bevel interpolation
- [ ] (c_interp) color interpolation
- [ ] (d_interp) dissolve interpolation
- [ ] (lod) level of detail
- [x] (usmtl) material name
- [x] (mtllib) material library
- [ ] (shadow_obj) shadow casting
- [ ] (trace_obj) ray tracing
- [ ] (ctech) curve approximation technique
- [ ] (stech) surface approximation 
