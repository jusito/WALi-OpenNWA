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

      virtual ~LLVMValueSource() override;

      virtual bool equal( KeySource* rhs ) override;

      virtual size_t hash() const override;

      virtual std::ostream& print( std::ostream& o ) const override;

      const  llvm::Value *getLLVMValue() const;

    private:
      const  llvm::Value *value;

  }; // class LLVMValueSource

} // namespace wali

#endif  // wali_INT_SOURCE_GUARD
