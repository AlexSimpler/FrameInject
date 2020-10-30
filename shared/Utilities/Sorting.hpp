#pragma once

public ref class ListViewColumnSorter : System::Collections::IComparer
{
public:
    ListViewColumnSorter() {
        // Initialize the column to '0'
        ColumnToSort = 0;

        // Initialize the sort order to 'none'
        OrderOfSort = System::Windows::Forms::SortOrder::None;

        // Initialize the CaseInsensitiveComparer object
        ObjectCompare = gcnew System::Collections::CaseInsensitiveComparer();
    }
    virtual int Compare(System::Object^ x, System::Object^ y);

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

    property int SortColumn {
        void ListViewColumnSorter::SortColumn::set(int value)
        {
            ColumnToSort = value;
        }

        int ListViewColumnSorter::SortColumn::get()
        {
            return ColumnToSort;
        }
    }
    property System::Windows::Forms::SortOrder SortOrder {
        void ListViewColumnSorter::SortOrder::set(System::Windows::Forms::SortOrder value)
        {
            OrderOfSort = value;
        }

        System::Windows::Forms::SortOrder ListViewColumnSorter::SortOrder::get()
        {
            return OrderOfSort;
        }

    }

};
