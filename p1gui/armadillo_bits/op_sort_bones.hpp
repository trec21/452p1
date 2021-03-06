// Copyright (C) 2008-2012 NICTA (www.nicta.com.au)
// Copyright (C) 2008-2012 Conrad Sanderson
// 
// This file is part of the Armadillo C++ library.
// It is provided without any warranty of fitness
// for any purpose. You can redistribute this file
// and/or modify it under the terms of the GNU
// Lesser General Public License (LGPL) as published
// by the Free Software Foundation, either version 3
// of the License or (at your option) any later version.
// (see http://www.opensource.org/licenses for more info)


//! \addtogroup op_sort
//! @{



class op_sort
  {
  public:
  
  template<typename eT>
  inline static void copy_row(eT* X, const Mat<eT>& A, const uword row);
  
  template<typename eT>
  inline static void copy_row(Mat<eT>& A, const eT* X, const uword row);
  
  template<typename eT>
  inline static void direct_sort(eT* X, const uword N, const uword sort_type = 0);
  
  template<typename eT>
  inline static void direct_sort_ascending(eT* X, const uword N);
  
  template<typename T1>
  inline static void apply(Mat<typename T1::elem_type>& out, const Op<T1,op_sort>& in);
  };



//! @}
