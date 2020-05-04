/// <summary>
/// This class is an implementation of the 'IComparer' interface.
/// </summary>
#include "../../shared/dependencies/dependencies.hpp"
#include "../../shared/Utilities/Sorting.hpp"

using namespace System::Windows::Forms;
using namespace msclr::interop;

void MarshalString(System::String^ s, std::string& os) {
    using namespace System::Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}


bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/// <summary>
/// This method is inherited from the IComparer interface.  It compares the two objects passed using a case insensitive comparison.
/// </summary>
/// <param name="x">First object to be compared</param>
/// <param name="y">Second object to be compared</param>
/// <returns>The result of the comparison. "0" if equal, negative if 'x' is less than 'y' and positive if 'x' is greater than 'y'</returns>
int ListViewColumnSorter::Compare(System::Object^ x, System::Object^ y)
{
    int compareResult;
    System::Windows::Forms::ListViewItem^ listviewX, ^listviewY;

    // Cast the objects to be compared to ListViewItem objects
    listviewX = cli::safe_cast<ListViewItem^>(x);
    listviewY = cli::safe_cast<ListViewItem^>(y);

    std::string subitemX = "";
    std::string subitemY = "";
    MarshalString(listviewX->SubItems[ColumnToSort]->Text, subitemX);
    MarshalString(listviewY->SubItems[ColumnToSort]->Text, subitemY);

    if (is_number(subitemX) || is_number(subitemY))
    {
        __int32 subitemX = System::Int32::Parse(listviewX->SubItems[ColumnToSort]->Text);
        __int32 subitemY = System::Int32::Parse(listviewY->SubItems[ColumnToSort]->Text);
        compareResult = (subitemX < subitemY) ? 1 : ((subitemX > subitemY) ? -1 : 0);
    }
    else {
        compareResult = ObjectCompare->Compare(listviewX->SubItems[ColumnToSort]->Text,
            listviewY->SubItems[ColumnToSort]->Text);
    }
    

    // Calculate correct return value based on object comparison
    if (OrderOfSort == System::Windows::Forms::SortOrder::Ascending)
    {
        // Ascending sort is selected, return normal result of compare operation
        return compareResult;
    }
    else if (OrderOfSort == System::Windows::Forms::SortOrder::Descending)
    {
        // Descending sort is selected, return negative result of compare operation
        return (-compareResult);
    }
    else
    {
        // Return '0' to indicate they are equal
        return 0;
    }
}

/// <summary>
/// Gets or sets the number of the column to which to apply the sorting operation (Defaults to '0').
/// </summary>

//void ListViewColumnSorter::SortColumn::set(int value)
//{
//    ColumnToSort = value;
//}
//
//int ListViewColumnSorter::SortColumn::get()
//{
//    return ColumnToSort;
//}

/// <summary>
/// Gets or sets the order of sorting to apply (for example, 'Ascending' or 'Descending').
/// </summary>
//void ListViewColumnSorter::SortOrder::set(System::Windows::Forms::SortOrder value)
//{
//    OrderOfSort = value;
//}
//
//System::Windows::Forms::SortOrder ListViewColumnSorter::SortOrder::get()
//{
//    return OrderOfSort;
//}

