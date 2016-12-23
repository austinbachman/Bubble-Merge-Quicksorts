// Program Information ////////////////////////////////////////////////////////
/**
 * @file SorterClass.cpp
 *
 * @brief Implementation file for SorterClass class
 * 
 * @details Implements all member methods of the SorterClass class
 *
 * @version 1.00 
 *          Austin Bachman (20 February 2016)
 *          Original code
 *
 * @Note Requires SimpleVector.cpp and SorterClass.h
 */

// Header files ///////////////////////////////////////////////////////////////

#include "SorterClass.h"
#include "SimpleVector.cpp"

/**
 * @brief Default/Initialization SorterClass constructor
 *
 * @details Constructs SorterClass with either default or given capacity
 *          
 * @pre assumes Uninitialized SorterClass object
 *
 * @post List of nodes is created for use as array
 *
 * @par Algorithm 
 *      Initializes class by calling parent constructor
 * 
 * @exception None
 *
 * @param [in] newCapacity
 *             Desired default or user-provided capacity
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
SorterClass<DataType>::SorterClass
       (
        int newCapacity // in: initial capacity for vector
       )
     : SimpleVector<DataType>( newCapacity )
   {
    // construct from parent
   }

/**
 * @brief Initialization fill constructor
 *
 * @details Constructs object with all elements filled
 *          
 * @pre Assumes uninitialized SorterClass object
 *
 * @post list of nodes is created for use as array
 *
 * @par Algorithm 
 *      Initializes class by calling parent constructor
 * 
 * @exception None
 *
 * @param [in] newCapacity 
 *             User-defined object capacity
 *
 * @param [in] fillValue 
 *             DataType fill value
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
SorterClass<DataType>::SorterClass
   ( 
    int newCapacity,          // in: new vector capacity
    const DataType &fillValue // in: fill value for all elements
   )
       : SimpleVector<DataType>( newCapacity, fillValue )
{
    // construct from parent
}

/**
 * @brief Copy constructor
 *
 * @details Creates local copy of all contents of parameter object
 *          
 * @pre Assumes uninitialized SorterClass object
 *
 * @par Algorithm 
 *      Calls parent constructor for copy process
 * 
 * @exception None
 *
 * @param [in] copiedVector
 *             Incoming Vector object
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
SorterClass<DataType>::SorterClass
   (
    const SorterClass<DataType> &copiedVector // in: other SorterClass object
   )
       : SimpleVector<DataType>( copiedVector )
{   
    // construct parent
}

/**
 * @brief Object destructor
 *
 * @details Removes or verifies removal of all data in SorterClass
 *          
 * @pre Assumes SorterClass capacity >= 0
 *
 * @par Algorithm
 *      Calls parent destructor
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
SorterClass<DataType>::~SorterClass
   ( 
    // no parameters
   )
{
    // parent class (SimpleVector) destructs
}

/**
 * @brief Appends DataItem to end
 *
 * @details Adds DataItem to end of list
 *          
 * @pre Assumes vectorSize data is correct
 *
 * @pre Assumes data found in elements, 
 *              vectorCapacity > vectorSize + 1
 *
 * @post Data is appended to end
 *       If vector has been filled, capacity is doubled
 *
 * @par Algorithm 
 *      Inserts at index of size, doubles capacity
 *      if vector has been filled
 * 
 * @exception None
 *
 * @param [in] addedItem
 *             Element to be appended to list
 *             
 * @return None
 *
 * @note None
 */
template <typename DataType>
void SorterClass<DataType>::add
   (
    const DataType &addedItem     // input: item to insert
   )
{
    insertAtIndex( this->getSize(), addedItem );

    if( this->getSize() == this->getCapacity() )
    {
        this->resize( this->getCapacity() * 2 );
    }
}

/**
 * @brief Finds and removes an item
 *
 * @details Removes item specified by user
 *          
 * @pre Assumes vectorSize data is correct
 *
 * @pre Assumes data found in elements, 
 *              vectorCapacity > vectorSize + 1
 *
 * @post Data has been removed from list
 *
 * @par Algorithm 
 *      Finds index for element, removes at index
 * 
 * @exception None
 *
 * @param [in] removedItem
 *             Element to be removed from list
 *             
 * @return Bool with success or failure
 *
 * @note None
 */
template<typename DataType>
bool SorterClass<DataType>::remove
   (
    DataType &removedItem     // input: item to find and remove
   )
{
    int index = findIndexFor( removedItem );
    DataType tmpItem;

    if( index >= 0 )
    {
        removeAtIndex( index, tmpItem );
        return true;       
    }

    return false;
}

/**
 * @brief Finds index of an item
 *
 * @details Used to find index for removal
 *          
 * @pre Assumes vectorSize data is correct
 *
 * @post Index of data item has been returned
 *
 * @par Algorithm 
 *      Loops through data, compared data to input
 * 
 * @exception None
 *
 * @param [in] searchItem
 *             Element to be found in list
 *             
 * @return Int with index of element
 *
 * @note None
 */
template<typename DataType>
int SorterClass<DataType>::findIndexFor
   (
    const DataType &searchItem     // input: item to search for
   )
{
    static const int LARGE_STR_LEN = 100;
    const int MAX_TESTS = 3;

    char sItem[ LARGE_STR_LEN ], indexItem[ LARGE_STR_LEN ];
    int index, position;
    bool found = false;

    searchItem.toString( sItem );


    for( index = 0; index < this->getSize(); index++ )
    {
        ( this->getAtIndex( index ) ).toString( indexItem );

        position = 0;

        while( position < MAX_TESTS )
        {
            found = true;

            if( sItem[position] != indexItem[position] )
            {
                found = false;
                break;
            }

            position++;
        }

        if( found )
        {
            return index;
        }
    }

    return NOT_FOUND;
}

/**
 * @brief Empty virtual method
 *
 * @details To be implemented in derived classes
 *          
 * @pre None
 *
 * @post None
 *
 * @par Algorithm 
 *      None
 * 
 * @exception None
 *
 * @param None
 *             
 * @return None
 *
 * @note None
 */
template<typename DataType>
void SorterClass<DataType>::sort
   (
    // no parameters
   )
{
    // empty virtual method
}

/**
 * @brief Copies data between elements
 *
 * @details Copies DataType value from one vector element to another
 *        using indices
 *          
 * @pre Assumes data found in elements, and that vectorCapacity > indexFrom 
 *              and vectorCapacity > indexTo
 *
 * @post vector element at indexTo contains the data found
 *       at element at indexFrom
 *
 * @par Algorithm 
 *      Acquires data using getAtIndex,
 *      assigns data using setAtIndex
 * 
 * @exception Boundary
 *            Exception called if from or to indices are out of bounds
 *
 * @param [in] indexTo
 *             Index for element to which data is copied
 *             
 * @param [in] indexFrom
 *             Index for element from which data is copied
 *             
 * @return None
 *
 * @note None
 */
template <typename DataType>
void SorterClass<DataType>::copyFromTo
   (
    int indexTo,   // in: index of to element
    int indexFrom  // in: index of from element
   )
{
    this->setAtIndex( indexTo, this->getAtIndex( indexFrom ) );
}

/**
 * @brief Swaps data between elements
 *
 * @details Acquires DataType quantities from two elements, swaps between them
 *          
 * @pre Assumes data found in elements, and that vectorCapacity > oneIndex 
 *              and vectorCapacity > otherIndex
 *
 * @post vector element at oneIndex contains the data found
 *       at element at otherIndex, and vector element at otherIndex
 *       contains data found at oneIndex
 *
 * @par Algorithm 
 *      Acquires data for both items using getAtIndex,
 *      assigns data to opposite indices using setAtIndex
 * 
 * @exception Boundary
 *            Exception called if one or other indices are out of bounds
 *
 * @param [in] oneIndex
 *             Index for element of one of two elements to be swapped
 *             
 * @param [in] indexFrom
 *             Index for element of other of two elements to be swapped
 *             
 * @return None
 *
 * @note None
 */
template <typename DataType>
void SorterClass<DataType>::swapBetween
   (
    int oneIndex,   // in: index of to element
    int otherIndex  // in: index of from element
   )
{
    DataType tempDataFromOne, tempDataFromOther;

    tempDataFromOne = this->getAtIndex( oneIndex );

    tempDataFromOther = this->getAtIndex( otherIndex );

    this->setAtIndex( oneIndex, tempDataFromOther );

    this->setAtIndex( otherIndex, tempDataFromOne );
}

/**
 * @brief Inserts DataItem at specified index
 *
 * @details Shifts all data above inserted location up
 *          
 * @pre Assumes Assumes vectorSize data is correct
 *
 * @pre Assumes data found in elements, 
 *              vectorCapacity > vectorSize + 1
 *
 * @post All data is moved up from insertion location,
 *       given DataType item inserted at insertion location
 *
 * @par Algorithm 
 *      Copies data from each element up to next element using copyFromTo,
 *      inserts item using setAtIndex
 * 
 * @exception Boundary
 *            Exception called if one or other indices are out of bounds
 *
 * @param [in] insertIndex
 *             Index for element of element to acquire inserted data
 *             
 * @param [in] itemToInsert
 *             Data item to be inserted into vector
 *             
 * @return None
 *
 * @note None
 */
template <typename DataType>
void SorterClass<DataType>::insertAtIndex
   (
    int insertIndex,              // in: index at which to insert data
    const DataType &itemToInsert  // in: DataType data to be inserted
   )
{
    int workingIndex = this->getSize();

    while( workingIndex > insertIndex )
       {
        copyFromTo( ( workingIndex - 1 ), workingIndex );

        workingIndex--;
       }

    this->setAtIndex( workingIndex, itemToInsert );

    this->incrementSize();
}

/**
 * @brief Removes DataItem at specified index
 *
 * @details Shifts all data above removed location down
 *          
 * @pre Assumes Assumes vectorSize data is correct
 *
 * @pre Assumes data found in elements
 *
 * @post All data is moved down by one element to the removal location,
 *       given DataType item removed at removal location,
 *       and passed back to calling function
 *
 * @par Algorithm
 *      Acquired data item from element 
 *      Copies data from each element down by one element to the removed index
 *      using copyFromTo, passes item back to calling function
 * 
 * @exception Boundary
 *            Exception called if one or other indices are out of bounds
 *
 * @param [in] removalIndex
 *             Index of element to be removed from vector
 *             
 * @param [out] removedItem
 *             Data removed from vector and passed back to calling function
 *             
 * @return None
 *
 * @note None
 */
template <typename DataType>
void SorterClass<DataType>::removeAtIndex
   (
    int removalIndex,              // in: index at which to remove data
    DataType &removedItem          // out: DataType data to be removed
   )
{
    int workingIndex = removalIndex;

    removedItem = this->getAtIndex( removalIndex );

    while( workingIndex < ( this->getSize() - 1 ) )
    {
        copyFromTo( workingIndex, ( workingIndex + 1 ) );

        workingIndex++;
    }

    this->decrementSize();
}