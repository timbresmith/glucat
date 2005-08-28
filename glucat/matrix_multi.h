#ifndef _GLUCAT_MATRIX_MULTI_H
#define _GLUCAT_MATRIX_MULTI_H
/***************************************************************************
    GluCat : Generic library of universal Clifford algebra templates
    matrix_multi.h : Declare a class for the matrix representation of a multivector
                             -------------------
    begin                : Sun 2001-12-09
    copyright            : (C) 2001 by Paul C. Leopardi
    email                : leopardi@bigpond.net.au
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; either version 2.1 of the  *
 *   License, or (at your option) any later version.                       *
 *   See http://www.fsf.org/copyleft/lesser.html for details               *
 ***************************************************************************
 This library is based on a prototype written by Arvind Raja and was
 licensed under the LGPL with permission of the author. See Arvind Raja,
 "Object-oriented implementations of Clifford algebras in C++: a prototype",
 in Ablamowicz, Lounesto and Parra (eds.)
 "Clifford algebras with numeric and symbolic computations", Birkhauser, 1996.
 ***************************************************************************
     See also Arvind Raja's original header comments in glucat.h
 ***************************************************************************/

namespace glucat
{
  template< typename Scalar_T, const index_t LO, const index_t HI >
  class framed_multi;  // forward

  template< typename Scalar_T, const index_t LO, const index_t HI >
  class matrix_multi;  // forward

  /// Read multivector from input
  template< typename Scalar_T, const index_t LO, const index_t HI >
  std::istream&
  operator>> (std::istream& s, matrix_multi<Scalar_T,LO,HI>& val);

  /// Write multivector to output
  template< typename Scalar_T, const index_t LO, const index_t HI >
  std::ostream&
  operator<< (std::ostream& os, const matrix_multi<Scalar_T,LO,HI>& val);

  /// A matrix_multi<Scalar_T,LO,HI> is a matrix approximation to a multivector
  template< typename Scalar_T, const index_t LO = DEFAULT_LO, const index_t HI = DEFAULT_HI >
  class matrix_multi :
  public clifford_algebra< Scalar_T, index_set<LO,HI>, matrix_multi<Scalar_T,LO,HI> >
  {
  public:
    typedef matrix_multi                               multivector_t;
    typedef multivector_t                              matrix_multi_t;
    typedef Scalar_T                                   scalar_t;
    typedef index_set<LO,HI>                           index_set_t;
    typedef std::pair< const index_set_t, Scalar_T >   pair_t;
    typedef std::vector<Scalar_T>                      vector_t;
    typedef error<multivector_t>                       error_t;

//  Use friend_maker to make friendship into legal C++
//  Ref: Matthew Wilson, "Friendly Templates", 
//  C/C++ Users Journal > CUJ Web Exclusives > 2003 > December 2003
//  http://www.cuj.com/documents/s=8942/cujweb0312wilson/
//
    typedef framed_multi<Scalar_T,LO,HI>               framed_multi_t;
    struct friend_maker
    {
      typedef framed_multi<Scalar_T,LO,HI>             framed_multi_t;
    };
    friend class _GLUCAT_USE_STRUCT_NAME(friend_maker) framed_multi_t;
  private:
    typedef ublas::row_major                           orientation_t;
    typedef ublas::compressed_matrix< Scalar_T, orientation_t >
                                                       matrix_t;
    typedef typename matrix_t::size_type               matrix_index_t;
  public:
    /// Class name used in messages
    static const std::string classname();
    /// Destructor
    ~matrix_multi() {};
    /// Default constructor
    matrix_multi();
    /// Construct a multivector, within a given frame, from a given multivector
    matrix_multi(const multivector_t& val, 
                 const index_set_t& frm, const bool prechecked = false);
    /// Construct a multivector from an index set and a scalar coordinate
    matrix_multi(const index_set_t& ist, const Scalar_T& crd);
    /// Construct a multivector, within a given frame, from an index set and a scalar coordinate
    matrix_multi(const index_set_t& ist, const Scalar_T& crd,
                 const index_set_t& frm, const bool prechecked = false);
    /// Construct a multivector from a scalar (within a frame, if given)
    matrix_multi(const Scalar_T& scr, const index_set_t& frm = index_set_t());
    /// Construct a multivector from an int (within a frame, if given)
    matrix_multi(const int scr, const index_set_t& frm = index_set_t());
    /// Construct a multivector, within a given frame, from a given vector
    matrix_multi(const vector_t& vec,
                 const index_set_t& frm, const bool prechecked = false);
    /// Construct a multivector from a string: eg: "3+2{1,2}-6.1e-2{2,3}"
    matrix_multi(const std::string& str);
    /// Construct a multivector, within a given frame, from a string: eg: "3+2{1,2}-6.1e-2{2,3}"
    matrix_multi(const std::string& str,
                 const index_set_t& frm, const bool prechecked = false);
    /// Construct a multivector from a framed_multi_t
    matrix_multi(const framed_multi_t& val);
    /// Construct a multivector, within a given frame, from a framed_multi_t
    matrix_multi(const framed_multi_t& val,
                 const index_set_t& frm, const bool prechecked = false);
    /// Use generalized FFT to construct a matrix_multi_t 
    const matrix_multi_t fast_matrix_multi(const index_set_t& frm) const;
    /// Use inverse generalized FFT to construct a framed_multi_t
    const framed_multi_t fast_framed_multi() const;
  private:
    /// Construct a multivector within a given frame from a given matrix
    matrix_multi(const matrix_t& mtx, const index_set_t& frm);
    /// Create a basis element matrix within the current frame
    const matrix_t     basis_element(const index_set<LO,HI>& ist) const;
  public:
    _GLUCAT_CLIFFORD_ALGEBRA_OPERATIONS

    /// Assignment operator
    multivector_t&     operator= (const multivector_t& rhs);
    friend std::istream&
      operator>> <>(std::istream& s, multivector_t& val);
    friend std::ostream&
      operator<< <>(std::ostream& os, const multivector_t& val);
    friend std::ostream&
      operator<< <>(std::ostream& os, const pair_t& term);
  private:
    /// Add a term, if non-zero
    multivector_t&     operator+= (const pair_t& rhs);
    // Data members
    /// Index set representing the frame for the subalgebra which contains the multivector
    index_set_t        m_frame;
    /// Matrix value representing the multivector within the folded frame
    matrix_t           m_matrix;
  };
}
#endif  // _GLUCAT_MATRIX_MULTI_H
