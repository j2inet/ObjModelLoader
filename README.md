# OBJ Model Loader

This is my take on loading a subset of the OBJ model format. The OBJ format for 3D models was
developer by WaveFront for interoperability. WaveFront was later acquired by Autodesk. This source
is not meant to load all possible constructs that can be found in an OBJ file. 

Written by Joel Ivory Johnson

# Specification Source

I looked at several sources and decided on this document as a spec to build from. 

https://paulbourke.net/dataformats/obj/obj_spec.pdf

OBJ format lines

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
