#pragma once

public ref class ListViewColumnSorter : System::Collections::IComparer
{
public:

    ListViewColumnSorter();
    virtual int Compare(System::Object^ x, System::Object^ y);

private:
    /// <summary>
    /// Specifies the column to be sorted
    /// </summary>
    int ColumnToSort;

    /// <summary>
    /// Specifies the order in which to sort (i.e. 'Ascending').
    /// </summary>
    System::Windows::Forms::SortOrder OrderOfSort;

    /// <summary>
    /// Case insensitive comparer object
    /// </summary>
    System::Collections::CaseInsensitiveComparer^ ObjectCompare;

    property int SortColumn;
    property System::Windows::Forms::SortOrder SortOrder;
};
