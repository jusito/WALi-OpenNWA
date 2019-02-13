/**
 * @author Nicholas Kidd
 * @version $Revision$
 */

#include <functional>
#include "wali/Common.hpp"
#include "wali/LLVMValueSource.hpp"
#include "wali/hm_hash.hpp"

namespace wali
{
  LLVMValueSource::LLVMValueSource( const llvm::Value *v ) : value(v) {}

  LLVMValueSource::~LLVMValueSource() {}

  bool LLVMValueSource::equal( KeySource* rhs )
  {
    LLVMValueSource *vsrc = dynamic_cast< LLVMValueSource* >(rhs);
    if( vsrc != 0 )
      return value == vsrc->value;
    else
      return false;
  }

  size_t LLVMValueSource::hash() const
  {
    return std::hash<size_t>()(reinterpret_cast<size_t>(value));
  }

  std::ostream& LLVMValueSource::print( std::ostream& o ) const
  {
    return o << "lvstest";
  }

  const llvm::Value *LLVMValueSource::getLLVMValue() const
  {
    return value;
  }

} // namespace wali

