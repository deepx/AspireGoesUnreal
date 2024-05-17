#include "AspireGoesUnrealBPLibrary.h"
#include "AspireGoesUnreal.h"

UAspireGoesUnrealBPLibrary::UAspireGoesUnrealBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("AspireGoesUnreal loaded."));

}

float UAspireGoesUnrealBPLibrary::AspireGoesUnrealSampleFunction(float Param)
{
	return -1;
}

TMap<FString, FString> UAspireGoesUnrealBPLibrary::GetAspireServices(bool useHttps = true)
{
	TMap<FString, FString> environmentVariables;
	environmentVariables.Empty();
	for (char ** current = environ; *current; current++)
	{
		
		FString envVar(*current);
		FString key;
		key.Empty();
		FString temp;
		temp.Empty();
		int32 position = envVar.Find("=");

		key = envVar.Left(position);
		
		if (key.Contains("services__"))
		{
			temp = key.Right(key.Len() - 10);
			if (useHttps && temp.Contains("__https__"))
			{
				key.Empty();
				key = temp.Replace(TEXT("__https_"), TEXT(""), ESearchCase::IgnoreCase);
				FString value = envVar.Right(envVar.Len() - position - 1);
				environmentVariables.Add(key, value);
			}
			else if(!useHttps && temp.Contains("__http__"))
			{
				FString value = envVar.Right(envVar.Len() - position - 1);
				environmentVariables.Add(temp, value);
			}
		}
	}
	return environmentVariables;
}

