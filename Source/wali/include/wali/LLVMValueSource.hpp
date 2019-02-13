#ifndef wali_LLVMVALUE_SOURCE_GUARD
#define wali_LLVMVALUE_SOURCE_GUARD 1

/*!
 * @author Nicholas Kidd
 */

#include "wali/Common.hpp"
#include "wali/KeySource.hpp"

namespace wali
{
  class LLVMValueSource : public KeySource
  {
    public:
      LLVMValueSource( const llvm::Value *v );

      virtual ~LLVMValueSource();

      virtual bool equal( KeySource* rhs );

      virtual size_t hash() const;

      virtual std::ostream& print( std::ostream& o ) const;

      const  llvm::Value *getLLVMValue() const;

    private:
      const  llvm::Value *value;

  }; // class LLVMValueSource

} // namespace wali

#endif  // wali_INT_SOURCE_GUARD

