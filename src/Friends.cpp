#include "StaticMembers.hpp"

std::ostream& operator<<(std::ostream& p_output_stream, const person& p_this) {
    p_output_stream
        << "Person: [ "
        << p_this.name
        << ", "
        << p_this.age
        << " ]";

    return p_output_stream;
}
