#ifndef _GLUCAT_QD_H
#define _GLUCAT_QD_H
/***************************************************************************
    GluCat : Generic library of universal Clifford algebra templates
    qd.h : Define functions for dd_real and qd_real as scalar_t
                             -------------------
    begin                : 2010-03-23
    copyright            : (C) 2010-2014 by Paul C. Leopardi
 ***************************************************************************

    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this library.  If not, see <http://www.gnu.org/licenses/>.

 ***************************************************************************
 This library is based on a prototype written by Arvind Raja and was
 licensed under the LGPL with permission of the author. See Arvind Raja,
 "Object-oriented implementations of Clifford algebras in C++: a prototype",
 in Ablamowicz, Lounesto and Parra (eds.)
 "Clifford algebras with numeric and symbolic computations, Birkhauser, 1996."
 ***************************************************************************
 See also Arvind Raja's original header comments and references in glucat.h
 ***************************************************************************/

#include "glucat/scalar.h"

#if defined(_GLUCAT_USE_QD)
# include <qd/qd_real.h>
# if defined(QD_API)

namespace glucat
{
  /// Extra traits which extend numeric limits
  // Reference: [AA], 2.4, p. 30-31

  /// Promoted type for double
  template<>
  struct
  numeric_traits<double>::
  promoted {typedef dd_real type;};

  /// Promoted type for long double
  template<>
  struct
  numeric_traits<long double>::
  promoted {typedef dd_real type;};

#define _GLUCAT_QD_F(_T, _F) \
  template<>           \
  inline               \
  const _T             \
  numeric_traits<_T>:: \
  _F(const _T& val)    \
  { return ::_F(val); }

  /// Smart isnan for dd_real
  template<>
  inline
  bool
  numeric_traits<dd_real>::
  isNaN(const dd_real& val)
  { return val.isnan(); }

  /// Smart isinf for dd_real
  template<>
  inline
  bool
  numeric_traits<dd_real>::
  isInf(const dd_real& val)
  { return val.isinf(); }

  /// Smart isnan or isinf for dd_real
  template<>
  inline
  bool
  numeric_traits<dd_real>::
  isNaN_or_isInf(const dd_real& val)
  { return val.isnan() || val.isinf(); }

  /// to_int for dd_real
  template<>
  inline
  int
  numeric_traits<dd_real>::
  to_int(const dd_real& val)
  { return ::to_int(val); }

  /// to_double for dd_real
  template<>
  inline
  double
  numeric_traits<dd_real>::
  to_double(const dd_real& val)
  { return ::to_double(val); }

  /// Promoted type for dd_real
  template<>
  struct
  numeric_traits<dd_real>::
  promoted {typedef qd_real type;};

  /// Demoted type for dd_real
  template<>
  struct
  numeric_traits<dd_real>::
  demoted {typedef double type;};

  /// Modulo function for dd_real
  template<>
  inline
  const dd_real
  numeric_traits<dd_real>::
  fmod(const dd_real& lhs, const dd_real& rhs)
  { return ::fmod(lhs, rhs); }

  /// pow for dd_real
  template<>
  inline
  const dd_real
  numeric_traits<dd_real>::
  pow(const dd_real& val, int n)
  {
    dd_real result = 1.0;
    dd_real pow2 = val;
    for (int k = n; k != 0; pow2 *= pow2, k /= 2)
      if (k % 2)
        result *= pow2;
    return result;
  }

  /// Pi for dd_real
  template<>
  inline
  const dd_real
  numeric_traits<dd_real>::
  pi()
  { return dd_real::_pi; }

  /// log(2) for dd_real
  template<>
  inline
  const dd_real
  numeric_traits<dd_real>::
  ln_2()
  { return dd_real::_log2; }

  /// Exp of dd_real
  _GLUCAT_QD_F(dd_real, exp)

  /// Log of dd_real
  _GLUCAT_QD_F(dd_real, log)

  /// Cosine of dd_real
  _GLUCAT_QD_F(dd_real, cos)

  /// Inverse cosine of dd_real
  _GLUCAT_QD_F(dd_real, acos)

  /// Hyperbolic cosine of dd_real
  _GLUCAT_QD_F(dd_real, cosh)

  /// Sine of dd_real
  _GLUCAT_QD_F(dd_real, sin)

  /// Inverse sine of dd_real
  _GLUCAT_QD_F(dd_real, asin)

  /// Hyperbolic sine of dd_real
  _GLUCAT_QD_F(dd_real, sinh)

  /// Tangent of dd_real
  _GLUCAT_QD_F(dd_real, tan)

  /// Inverse tangent of dd_real
  _GLUCAT_QD_F(dd_real, atan)

  /// Hyperbolic tangent of dd_real
  _GLUCAT_QD_F(dd_real, tanh)

  /// Smart isnan for qd_real
  template<>
  inline
  bool
  numeric_traits<qd_real>::
  isNaN(const qd_real& val)
  { return val.isnan(); }

  /// Smart isinf for qd_real
  template<>
  inline
  bool
  numeric_traits<qd_real>::
  isInf(const qd_real& val)
  { return val.isinf(); }

  /// Smart isnan or isinf for qd_real
  template<>
  inline
  bool
  numeric_traits<qd_real>::
  isNaN_or_isInf(const qd_real& val)
  { return val.isnan() || val.isinf(); }

  /// to_int for qd_real
  template<>
  inline
  int
  numeric_traits<qd_real>::
  to_int(const qd_real& val)
  { return ::to_int(val); }

  /// to_double for qd_real
  template<>
  inline
  double
  numeric_traits<qd_real>::
  to_double(const qd_real& val)
  { return ::to_double(val); }

  /// Promoted type for qd_real
  template<>
  struct
  numeric_traits<qd_real>::
  promoted {typedef qd_real type;};

  /// Demoted type for qd_real
  template<>
  struct
  numeric_traits<qd_real>::
  demoted {typedef qd_real type;};

  /// Modulo function for qd_real
  template<>
  inline
  const qd_real
  numeric_traits<qd_real>::
  fmod(const qd_real& lhs, const qd_real& rhs)
  { return ::fmod(lhs, rhs); }

  /// pow for qd_real
  template<>
  inline
  const qd_real
  numeric_traits<qd_real>::
  pow(const qd_real& val, int n)
  {
    qd_real result = 1.0;
    qd_real pow2 = val;
    for (int k = n; k != 0; pow2 *= pow2, k /= 2)
      if (k % 2)
        result *= pow2;
    return result;
  }

  /// Pi for qd_real
  template<>
  inline
  const qd_real
  numeric_traits<qd_real>::
  pi()
  { return qd_real::_pi; }

  /// log(2) for qd_real
  template<>
  inline
  const qd_real
  numeric_traits<qd_real>::
  ln_2()
  { return qd_real::_log2; }

  /// Exp of qd_real
  _GLUCAT_QD_F(qd_real, exp)

  /// Log of qd_real
  _GLUCAT_QD_F(qd_real, log)

  /// Cosine of qd_real
  _GLUCAT_QD_F(qd_real, cos)

  /// Inverse cosine of qd_real
  _GLUCAT_QD_F(qd_real, acos)

  /// Hyperbolic cosine of qd_real
  _GLUCAT_QD_F(qd_real, cosh)

  /// Sine of qd_real
  _GLUCAT_QD_F(qd_real, sin)

  /// Inverse sine of qd_real
  _GLUCAT_QD_F(qd_real, asin)

  /// Hyperbolic sine of qd_real
  _GLUCAT_QD_F(qd_real, sinh)

  /// Tangent of qd_real
  _GLUCAT_QD_F(qd_real, tan)

  /// Inverse tangent of qd_real
  _GLUCAT_QD_F(qd_real, atan)

  /// Hyperbolic tangent of qd_real
  _GLUCAT_QD_F(qd_real, tanh)
}

# endif
#endif

#endif // _GLUCAT_QD_H
