// ------------------------------------------------------------------------------
// Copyright (c) 2015 GeometryFactory (FRANCE)
// Distributed under the Boost Software License, Version 1.0. (See accompany-
// ing file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// ------------------------------------------------------------------------------ 


#ifndef SWIG_CGAL_PMP_POLYGON_MESH_SLICER_H
#define SWIG_CGAL_PMP_POLYGON_MESH_SLICER_H

#include <SWIG_CGAL/Common/Macros.h>
#include <SWIG_CGAL/Common/Iterator.h>
#include <SWIG_CGAL/Kernel/Plane_3.h>
#include <SWIG_CGAL/Common/Input_iterator_wrapper.h>
#include <SWIG_CGAL/Common/Output_iterator_wrapper.h>

#include <CGAL/Polygon_mesh_slicer.h>

/* #if !SWIG_CGAL_NON_SUPPORTED_TARGET_LANGUAGE
template <class Primitive_object>
struct Primitive_iterator_helper
{
  typedef boost::function_output_iterator< Container_writer<Point_3,typename internal::Converter<Primitive_object>::result_type > >     output;
  typedef boost::function_output_iterator< Container_writer<std::pair<Object,Primitive_object>,std::pair<CGAL::Object,typename internal::Converter<Primitive_object>::result_type > > >     output2;
};

typedef std::pair<Input_iterator_wrapper<Point_3,Point_3::cpp_base>,Input_iterator_wrapper<Point_3,Point_3::cpp_base> > Point_range;
#else
typedef Generic_input_iterator<Point_3> Point_range;
#endif
 */

template <class Polyhedron_wrapper>
class Polygon_mesh_slicer_wrapper
{
  typedef Polygon_mesh_slicer_wrapper<Polyhedron_wrapper> Self;
  //disable deep copy
  Self deepcopy();
  void deepcopy(const Self&);

public:
  #ifndef SWIG
  typedef CGAL::Polygon_mesh_slicer<typename Polyhedron_wrapper::cpp_base, EPIC_Kernel> cpp_base;
  cpp_base data;
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data()       {return data;}
  #endif

  Polygon_mesh_slicer_wrapper(Polyhedron_wrapper& poly)
    : data(poly.get_data())
  {}

  void slice(const Plane_3& plane)
  {
    std::vector< std::vector<EPIC_Kernel::Point_3> > output;
    data(plane.get_data(), std::back_inserter(output));
    std::cout << output.size() << "\n";
  }
  //all_intersected_primitives
/*   #if !SWIG_CGAL_NON_SUPPORTED_TARGET_LANGUAGE
  void all_intersected_primitives (const Segment_3 & query, typename Primitive_iterator_helper<Primitive_id>::output out) {data.all_intersected_primitives(query.get_data(),out);}
  #else
  void all_intersected_primitives (const Segment_3 & query, Generic_output_iterator<Primitive_id> out) {data.all_intersected_primitives(query.get_data(),out);}
  #endif */
};


#endif //SWIG_CGAL_PMP_POLYGON_MESH_SLICER_H
