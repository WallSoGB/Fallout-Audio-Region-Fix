#pragma once

#include "BaseFormComponent.hpp"
#include "BSString.hpp"

class TESSoundFile : public BaseFormComponent {
public:
	TESSoundFile();
	~TESSoundFile();

	virtual void	SetSoundFile(const char* apPath);

	BSString	strPath;

	const char* GetPath() const;
};

ASSERT_SIZE(TESSoundFile, 0xC);