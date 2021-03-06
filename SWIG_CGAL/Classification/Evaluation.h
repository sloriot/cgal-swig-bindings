// ------------------------------------------------------------------------------
// Copyright (c) 2020 GeometryFactory (FRANCE)
// Distributed under the Boost Software License, Version 1.0. (See accompany-
// ing file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// ------------------------------------------------------------------------------

#ifndef SWIG_CGAL_CLASSIFICATION_EVALUATION_H
#define SWIG_CGAL_CLASSIFICATION_EVALUATION_H

#include <SWIG_CGAL/Common/Reference_wrapper.h>
#include <SWIG_CGAL/Common/Macros.h>

#include <SWIG_CGAL/Point_set_3/Point_set_3.h>

#include <SWIG_CGAL/Classification/Range_wrapper.h>

template <typename Evaluation_base, typename Label_set>
class Evaluation_wrapper
{
  SWIG_CGAL_INIT_WRAPPER_CLASS (Evaluation_base, data_sptr);

public:

  Evaluation_wrapper (Label_set labels,
                      typename Point_set_3_wrapper<CGAL_PS3>::Int_iterator ground_truth,
                      typename Point_set_3_wrapper<CGAL_PS3>::Int_iterator result)
    : data_sptr (new Evaluation_base (labels.get_data(), Range_wrapper(ground_truth), Range_wrapper(result)))
  {

  }

  double precision (typename Label_set::Label label)
  {
    return data_sptr->precision (label.get_data());
  }

  double recall (typename Label_set::Label label)
  {
    return data_sptr->recall (label.get_data());
  }

  double f1_score (typename Label_set::Label label)
  {
    return data_sptr->f1_score (label.get_data());
  }

  double intersection_over_union (typename Label_set::Label label)
  {
    return data_sptr->intersection_over_union (label.get_data());
  }

  SWIG_CGAL_FORWARD_CALL_0 (double, accuracy)
  SWIG_CGAL_FORWARD_CALL_0 (double, mean_f1_score)
  SWIG_CGAL_FORWARD_CALL_0 (double, mean_intersection_over_union)
};


#endif // SWIG_CGAL_CLASSIFICATION_EVALUATION_H
